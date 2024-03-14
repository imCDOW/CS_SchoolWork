import java.util.Scanner;
// Apologies if you are reading this, I did not mean to submit the same file twice, here is the corrected code, but, if you choose to not accept the late submission I fully understand and apologigse for the inconvienice
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the values of x and y: ");
        int x = input.nextInt();
        int y = input.nextInt();
        input.close();

        int result = multiply(x, y);
        System.out.println(x + " times " + y + " is " + result);
    }

    public static int multiply(int x, int y) {
        if (x < y)
            return multiply(y, x);
        else if (y != 0)
            return x + multiply(x, y - 1);
        else
            return 0;
    }
}