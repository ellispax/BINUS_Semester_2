import java.util.*;
public class Question1 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int arry[] = new int[10];
        System.out.println("Enter Ten Integer Numbers: ");
        for(int i = 0; i< arry.length;i++){
            System.out.print(": ");
            arry[i] = sc.nextInt();
        }

        System.out.println("The integers entered are: ");
        for (int i = 0; i< arry.length; i++){
            System.out.println(arry[i]);
        }

    }
}
