
import java.util.*;
public class Question4 {
    public static void main(String args[]){
      int arry[] ={1,2,3,1,43,5,67,8,99,3,2};
      int sum = 0;
      int product = 1;

      for (int num: arry){
          sum = sum + num;
          product = product * num;

      }
       System.out.print("The Sum of Array Elements is: ");System.out.println(sum);
       System.out.print("The Product of Array Elements is: ");System.out.println(product);

    }
}
