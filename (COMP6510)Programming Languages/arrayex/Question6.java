
import java.util.*;
public class Question6 {

   static void checkArray(int arry[], int n){
       boolean flag = true;

       for (int i= 0; i <=n/2 && n !=0; i++){
           if (arry[i] != arry[n-i-1]){
                   flag = false;
                   break;
           }
       }
       if (flag == false){
           System.out.println("Array Are not the the same forward and backwards" );
       }
       else{
           System.out.println("The Array is the same Forward and Backwards.");
       }

   }

   public static void main(String args[]){
       int arry[] = {1,2,3,3,2,1};
       int n = arry.length;

       checkArray(arry, n);
   }
}
