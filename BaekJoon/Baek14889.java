//back-tracking
import java.util.Scanner;
import java.util.Stack;
import java.util.Iterator;

class Main {

  static int[][] power;
  static Stack<Integer> team = new Stack<> ();
  static int n;
  static int min = Integer.MAX_VALUE;

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    n = sc.nextInt();
    power = new int[n][n];

    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        power[i][j] = sc.nextInt();
      }
    }
  
    sc.close();
    solu(0, 0);

    System.out.println(min);

  }

  public static void solu(int index, int cnt){
    if(cnt == n/2){
      calPower();
      return;
    }
    
    for(int i=index;i<n;i++){
      team.push(i);
      solu(i+1, cnt+1);
      team.pop();
    }
  }

  public static void calPower(){
    int index = 0;
    int index2 = 0;
    int[] group = new int[n/2];
    int[] tempTeam = new int[n/2];
    int team1=0, team2=0;
    for(int i=0;i<n;i++){
      if(team.search(i) == -1){

        tempTeam[index2] = i;
        index2++;
      }
    }

    Iterator value = team.iterator();
    while(value.hasNext()){
      group[index] = (int)value.next();
      index++;
    }

    for(int i=0;i<n/2-1;i++){
      for(int j=i+1;j<n/2;j++){
        team1 = team1+power[group[i]][group[j]]+power[group[j]][group[i]];
        team2 = team2+power[tempTeam[i]][tempTeam[j]]+power[tempTeam[j]][tempTeam[i]];   
      }
    }

    min = Math.min(min, Math.abs(team1-team2));
  }
}
