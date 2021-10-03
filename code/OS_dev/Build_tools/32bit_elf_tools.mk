TOOLDIR := $(abspath $(HOME)/.local)

BIN_DIR := $(TOOLDIR)/bin/i686-elf
LIB_DIR := $(TOOLDIR)/lib/i686-elf

BUILD_DIR := $(BIN_DIR)/build

BINUTILS_VERSION := 2.32
GDB_VERSION := 8.3.1
GCC_VERSION := 9.2.0

BINUTILS_BUILD_DIR := $(BUILD_DIR)/binutils-$(BINUTILS_VERSION)
GCC_BUILD_DIR := $(BUILD_DIR)/gcc-$(GCC_VERSION)
GDB_BUILD_DIR := $(BUILD_DIR)/gdb-$(GDB_VERSION)

BINUTILS_CFG_ARGS := --with-sysroot --disable-nls --disable-werror
GCC_CFG_ARGS := --disable-nls --enable-languages=c,c++ --without-headers
GDB_CFG_ARGS := --disable-nls --disable-werror

WGET_ARGS = -nv
WGET := wget -P $(BUILD_DIR) $(WGET_ARGS)

.PHONY: all gdb gcc binutils clean

all: gdb gcc binutils
        @echo "Done!"
        make clean

clean:
        rm -rf $(BUILD_DIR)

$(BUILD_DIR):
        mkdir -pv $(BUILD_DIR)

$(LIB_DIR):
        mkdir -pv $(LIB_DIR)

gdb: $(BUILD_DIR) $(LIB_DIR) $(BUILD_DIR)/gdb-$(GDB_VERSION).tar.gz
        tar -C $(BUILD_DIR) -xf $(BUILD_DIR)/gdb-$(GDB_VERSION).tar.gz

        mkdir -p $(GDB_BUILD_DIR)/obj
        cd $(GDB_BUILD_DIR)/obj\
                && ../configure --target=i686-elf --prefix=$(GDB_BUILD_DIR)/obj $(GDB_CFG_ARGS)\
                && make -j 2 tooldir=$(GDB_BUILD_DIR)/obj\
                && make -j 2 tooldir=$(GDB_BUILD_DIR)/obj install\

        -mv $(GDB_BUILD_DIR)/obj/bin/* $(BIN_DIR)
        -mv $(GDB_BUILD_DIR)/obj/lib/* $(LIB_DIR)

        rm -rf $(GDB_BUILD_DIR)

binutils: $(BUILD_DIR) $(LIB_DIR) $(BUILD_DIR)/binutils-$(BINUTILS_VERSION).tar.gz
        tar -C $(BUILD_DIR) -xf $(BUILD_DIR)/binutils-$(BINUTILS_VERSION).tar.gz

        mkdir -p $(BINUTILS_BUILD_DIR)/obj
        cd $(BINUTILS_BUILD_DIR)/obj\
                && ../configure --target=i686-elf --prefix=$(BINUTILS_BUILD_DIR)/obj $(BINUTILS_CFG_ARGS)\
                && make -j tooldir=$(BINUTILS_BUILD_DIR)/obj\
                && make -j tooldir=$(BINUTILS_BUILD_DIR)/obj install\

        -mv $(BINUTILS_BUILD_DIR)/obj/bin/* $(BIN_DIR)
        -mv $(BINUTILS_BUILD_DIR)/obj/lib/* $(LIB_DIR)

        rm -rf $(BINUTILS_BUILD_DIR)


gcc: $(BUILD_DIR) $(LIB_DIR) $(BUILD_DIR)/gcc-$(GCC_VERSION).tar.gz
        tar -C $(BUILD_DIR) -xf $(BUILD_DIR)/gcc-$(GCC_VERSION).tar.gz

        mkdir -p $(GCC_BUILD_DIR)/obj
        cd $(GCC_BUILD_DIR)/obj\
                && ../configure --target=i686-elf --prefix=$(GCC_BUILD_DIR)/obj $(GCC_CFG_ARGS)\
                && make -j 2 tooldir=$(GCC_BUILD_DIR)/obj all-gcc\
                && make -j 2 tooldir=$(GCC_BUILD_DIR)/obj install-gcc\     //-j option depends on the number of cores , how many instructions to run at a time 

        -mv $(GCC_BUILD_DIR)/obj/bin/* $(BIN_DIR)
        -mv $(GCC_BUILD_DIR)/obj/lib/* $(LIB_DIR)

        rm -rf $(GCC_BUILD_DIR)

$(BUILD_DIR)/gdb-$(GDB_VERSION).tar.gz:
        $(WGET) http://ftp.gnu.org/gnu/gdb/gdb-$(GDB_VERSION).tar.gz

$(BUILD_DIR)/gcc-$(GCC_VERSION).tar.gz:
        $(WGET) http://ftp.gnu.org/gnu/gcc/gcc-$(GCC_VERSION)/gcc-$(GCC_VERSION).tar.gz

$(BUILD_DIR)/binutils-$(BINUTILS_VERSION).tar.gz:
        $(WGET) http://ftp.gnu.org/gnu/binutils/binutils-$(BINUTILS_VERSION).tar.gz