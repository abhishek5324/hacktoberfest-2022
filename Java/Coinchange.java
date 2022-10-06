import java.util.*;


public class  coinchange {
    public static void main(String[] args) {
      
      int x=3;
      ArrayList<Integer> v= new ArrayList<>();
      int[] arr = {1,2,3};
      
      find(x,arr,v,0);

      

    }
        public static void find(int x,int[] arr,ArrayList<Integer> v,int index){
          
          if(x==0){
            for(int i=0;i<v.size();i++){
              System.out.print(v.get(i)+" ");
            }
            System.out.println(" ");
            
            return;
          }
          if(index==3){
            return;
          }
          if(x<0){
            return;
          }
          v.add(arr[index]);
         
          find(x-arr[index],arr,v,index);
          v.remove(v.size()-1);
          find(x,arr,v,index+1);
        }
  }
