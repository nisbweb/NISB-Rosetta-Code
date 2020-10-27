package strings; //its a time consuming process it takes n*n time
public class Anagrams {

	public static void main(String[] args) {
		String a="aab";
		String b="abc";
		boolean isAnagram=false;
		boolean visited[]=new boolean[b.length()];
		if(a.length()==b.length()) {
			for(int i=0;i<a.length();i++) {
				char d=a.charAt(i);
				isAnagram=false;
				for(int j=0;j<b.length();j++) {
					if(b.charAt(j)==d && !visited[j]) {
						visited[j]=true;
						isAnagram=true;
						break;
					}
				}
				if(!isAnagram) {
					break;
				}
		   }
		}		
	
		if(isAnagram) {
			System.out.println("Anagram");
		} else {
			System.out.println("not an Anagram");
		}

	}

}