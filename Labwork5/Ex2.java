import java.lang.String;
import java.lang.Integer;
import java.util.ArrayList;
import java.util.Arrays;


class Test{
	ArrayList[][] stateAutomaton = new ArrayList[5][2];
	Test(){
		this.stateAutomaton[0][0] = new ArrayList<Integer>(Arrays.asList(0,2));
		this.stateAutomaton[0][1] = new ArrayList<Integer>(Arrays.asList(1));
		this.stateAutomaton[1][0] = new ArrayList<Integer>(Arrays.asList(3));
		this.stateAutomaton[1][1] = new ArrayList<Integer>(Arrays.asList(4));
		this.stateAutomaton[2][0] = new ArrayList<Integer>(Arrays.asList());
		this.stateAutomaton[2][1] = new ArrayList<Integer>(Arrays.asList(4));
		this.stateAutomaton[3][0] = new ArrayList<Integer>(Arrays.asList(3));
		this.stateAutomaton[3][1] = new ArrayList<Integer>(Arrays.asList());
		this.stateAutomaton[4][0] = new ArrayList<Integer>(Arrays.asList(3));
		this.stateAutomaton[4][1] = new ArrayList<Integer>(Arrays.asList(3));
	}
	boolean[] isAcceptState = {true,false,false,false,true};
	ArrayList<Integer> nextStates(ArrayList<Integer> currentStates, Integer input){
		ArrayList<Integer> allNextStates = new ArrayList<Integer>();
		for(int i=0;i<currentStates.size();i++){
			Integer currentState = currentStates.get(i);
			ArrayList<Integer> nextStates = stateAutomaton[currentState][input];
			if(nextStates.size() != 0){
				for(int j = 0; j<nextStates.size();j++){
					if (!allNextStates.contains(nextStates.get(j))) {
						allNextStates.add(nextStates.get(j));
					}
				}
			}
		}
		return allNextStates;
	}

	void printArray(ArrayList a){
		if(a.size()==0){
			System.out.println("size = 0");
			return;
		}
		for(int i = 0; i<a.size(); i++){
			System.out.println(a.get(i));
		}
	}


	Boolean isAcceptedString(String testString){
		int inputIndex = 0;
		ArrayList<Integer> finalStates = new ArrayList<Integer>();
		finalStates.add(0);
		while(inputIndex<testString.length()){
			Integer inputVal = Integer.parseInt(testString.substring(inputIndex,inputIndex+1));
			
			finalStates = nextStates(finalStates,inputVal);
			inputIndex++;
		}
		printArray(finalStates);
		for(int i = 0; i<finalStates.size();i++){
			if(isAcceptState[finalStates.get(i)]){
				return true;
			}
		}
		return false;
	}



	public static void main(String[] args){
		Test myTest = new Test();
		String testString = "00000011001";
		if(myTest.isAcceptedString(testString))
			System.out.println("Recognized");
		else
			System.out.println("Not Recognized");

	}
	

}	