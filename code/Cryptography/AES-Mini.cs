using System;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
namespace CoolAES
{
    class Program
    {
        public static void WriteL(string s) { Console.WriteLine(s); }
        public static void Write(string s) { Console.Write(s); }
        public static string Read() { return Console.ReadLine(); }
        public static AesCryptoServiceProvider Create(byte[] K)
        {
            if (K.Length < 32) { var a = K.ToList(); a.AddRange(new byte[32 - K.Length]); K = a.ToArray(); }
            return new AesCryptoServiceProvider { KeySize = 256, BlockSize = 128, Key = K, Padding = PaddingMode.None, Mode = CipherMode.ECB };
        }
        private static byte[] Dec(byte[] z, AesCryptoServiceProvider a)
        {
            var dec = a.CreateDecryptor(); byte[] resultArray = dec.TransformFinalBlock(z, 0, z.Length); return resultArray;
        }
        private static byte[] Enc(byte[] z, AesCryptoServiceProvider a) {
            var enc = a.CreateEncryptor(); var te = z.ToList(); while (te.Count % 16 != 0) te.Add(0x00); z = te.ToArray(); byte[] resultArray = enc.TransformFinalBlock(z, 0, z.Length); return resultArray; 
        }
        public static byte[] GB(string a) { return Encoding.UTF8.GetBytes(a); }
        public static string GS(byte[] z) { return Encoding.UTF8.GetString(z); }
        public static string ToB64(byte[] z) { return Convert.ToBase64String(z); }
        public static byte[] FromB64(string s) { return Convert.FromBase64String(s); }
        static void Main(string[] args) {
            WriteL("1 to encrypt, 2 to decrypt"); Write(">"); var a = Read(); 
            if (a == "1") { 
                WriteL("to encrypt:"); var t = Read(); WriteL("key:"); var k = Read(); var e = Create(GB(k)); WriteL(ToB64(Enc(GB(t), e))); 
            } else { 
                WriteL("to decrypt:"); var t = Read(); WriteL("key:"); var k = Read(); var e = Create(GB(k)); WriteL(GS(Dec(FromB64(t), e))); 
            } 
        }
    }
}