import java.util.*;
public class Question10 {
    public static void main(String args []){
        int arry [] = {1,4,2,4,2,1,4,5};
        System.out.println("Unsorted Array");
        for(int num : arry){
            System.out.print(num+ " ");
        }

        System.out.println();
        Arrays.sort(arry);

        System.out.println("The sorted array");
        for (int num : arry){
            System.out.print(num+" ");
        }

    }
}
