import java.util.Scanner;

class randomNumberJava {
    public static void play() {
        int max = 100;
        int min = 1;
        Scanner sc = new Scanner(System.in);
        int randomNo = (int) Math.floor(Math.random() * (max - min + 1) + min);
        int count = 1;
        while (true) {
            int guess;
            System.out.println("Guess a random number between 1 to 100");
            guess = sc.nextInt();
            if (guess > randomNo) {
                System.out.println("too high !!");
                count++;
            } else if (guess< randomNo) {
                System.out.println("too low !!");
                count++;
            } else {
                System.out.println("wow you found the number !!" + randomNo + " = " + guess);
                System.out.println("You have guesses the random number in " + count + " attempts");
                break;
            }
        }
    }

    public static void main(String[] args) {
        play();
    }
}