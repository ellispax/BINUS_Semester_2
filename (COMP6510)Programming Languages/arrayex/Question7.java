import java.util.*;
public class Question7 {

    public static void main(String args[]){
        int one[] = {};
        int two[] = {};
        Scanner sc = new Scanner(System.in);
        int arry[] = new int[10];
        System.out.println("Enter Ten Integer Numbers: ");
        for(int i = 0; i< arry.length;i++){
            System.out.print(": ");
            arry[i] = sc.nextInt();
        }

        one = Arrays.copyOfRange(arry,0,5); //java array slicing function
        two = Arrays.copyOfRange(arry, 5, 10);



        System.out.println("First half has: ");
        for (int i = 0; i< one.length; i++){
            System.out.println(one[i]);
        }

        System.out.println("Second half has: ");
        for (int i = 0; i< two.length; i++){
            System.out.println(two[i]);
        }


    }
}
