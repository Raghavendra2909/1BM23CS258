/*Write a java program which creates two threads, one thread
displaying “BMS College of Engineering” once every ten
seconds and another displaying “CSE” once every two
seconds.*/
public class threds {
    public static void main(String[] args) {
        // Thread for displaying "BMS College of Engineering" every 10 seconds
        Thread collegeThread = new Thread(() -> {
            try {
                while (true) {
                    System.out.println("BMS College of Engineering");
                    Thread.sleep(10000); // 10 seconds
                }
            } catch (InterruptedException e) {
                System.out.println("College Thread interrupted");
            }
        });

        // Thread for displaying "CSE" every 2 seconds
        Thread cseThread = new Thread(() -> {
            try {
                while (true) {
                    System.out.println("CSE");
                    Thread.sleep(2000); // 2 seconds
                }
            } catch (InterruptedException e) {
                System.out.println("CSE Thread interrupted");
            }
        });

        // Start both threads
        collegeThread.start();
        cseThread.start();
    }
}


