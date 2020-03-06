import java.util.*;
class Question9 {
    public static void main(String args[]){

        Scanner sc = new Scanner(System.in);
        int elements;
        System.out.println("How many elements do you want in your Array? ");
        elements = sc.nextInt();
        Integer arry[] = new Integer[elements];
        System.out.println("Enter Ten Integer Numbers: ");
        for(int i = 0; i< arry.length;i++){
            System.out.print(": ");
            arry[i] = sc.nextInt();
        }
        Collections.reverse(Arrays.asList(arry));
        System.out.print("New Array : ");
        System.out.println(Arrays.asList(arry));



    }
}
