import java.util.*;

public class Question3 {
    public static void main(String arg[]){
        Scanner sc = new Scanner(System.in);
        int arry[] = new int[4];
        System.out.println("Enter 20 Integer Numbers: ");
        for(int i = 0; i< arry.length;i++){
            System.out.print(": ");
            arry[i] = sc.nextInt();
        }

        int pos=0, neg=0, odd=0, even=0, zeros = 0;

        for (int i =0; i<arry.length;i++){
            if (arry[i] >=0){
                pos += 1;

            }
            else if (arry[i] < 0){
                neg += 1;
            }

            if (arry[i] % 2 == 0){
                even += 1;
            }
            else {
                odd += 1;

            }
            if (arry[i] == 0){
                zeros += 1;
            }
        }
        System.out.print("Number Of positive entries:");System.out.println(pos);
        System.out.print("Number of negative entries: ");System.out.println(neg);
        System.out.print("Number of Even entries: ");System.out.println(even);
        System.out.print("Number of odd entries: ");System.out.println(odd);
        System.out.print("Number of Zero entries: ");System.out.println(zeros);
    }
}
