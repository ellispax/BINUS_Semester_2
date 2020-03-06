import java.util.*;
public class Question2 {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int arry[] = new int[10];
        System.out.println("Enter Ten Integer Numbers: ");
        for(int i = 0; i< arry.length;i++){
            System.out.print(": ");
            arry[i] = sc.nextInt();
        }

        boolean flag = false;

        int num ;
        System.out.println("Enter Number that you want to find: ");
        num = sc.nextInt();
        //int i = 0;
        for (int i = 0;i < arry.length; i++){
            if (arry[i] == num){
                System.out.println("Number Found in the array list");
                flag = true;
                break;
            }

        }
        if (flag == false){
            System.out.println("Number not found");
        }



    }
}
