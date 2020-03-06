import java.util.*;
public class Question5 {
    //get max value
    public static int getMax(int[] Arry){
        int max = Arry[0];
        for(int i=1;i < Arry.length;i++){
            if(Arry[i] > max){
                max = Arry[i];
            }
        }
        return max;
    }

    //get minimun value
    public static int getMin(int[] Arry){
        int min = Arry[0];
        for(int i=1;i<Arry.length;i++){
            if(Arry[i] < min){
                min = Arry[i];
            }
        }
        return min;
    }
    //main function
    public static void main(String args[]){
        int arry[] = {2,3,4,77,8,22,3};

        int max = getMax(arry);
        System.out.println("Largest Value is: "+max);

        int min = getMin(arry);
        System.out.println("The smallest value is: "+min);
    }
}
