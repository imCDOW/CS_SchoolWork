import java.util.Scanner;
public class Main {
 
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int x;
        int y;
        System.out.println("Enter a number and then enter the number you would like to raise it to:");
        x = input.nextInt();
        y = input.nextInt();
        input.close();
        
        int answer = power(x, y);
        System.out.println(x + " to the power of " + y + " = " + answer);
    }

    public static int power(int num, int exponent) {
        if (exponent == 0) // base condition
            return 1;
        else
            return num * power(num, exponent - 1);
    }
}
