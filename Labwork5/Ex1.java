import java.lang.String;
import java.lang.Integer;

class Test{

	int[][] f = {{0,1},{0,2},{0,0},{2,1}};
	boolean[] isAccept = {true,false,false,true};

	boolean isAccept(String testString){
		int inputIndex = 0;
		int state = 0;
		while(inputIndex < testString.length()){

			Integer inputVal = Integer.parseInt(testString.substring(inputIndex,inputIndex+1));
			System.out.println(inputVal);
			state = this.f[state][inputVal];
			inputIndex++;
		}
		if(isAccept[state] == true)
			return true;
		else 
			return false;
	}
	public static void main(String[] args){
		Test myTest = new Test();
		String test = "01001010";
		if(myTest.isAccept(test)){
			System.out.println("yes");
		}
		else 
			System.out.println("no");
	}
}