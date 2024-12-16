// Short Interprocess Communication and Deadlock Demonstration

class SharedResource {
    private int data;
    private boolean isDataAvailable = false;

    public synchronized void produce(int value) {
        while (isDataAvailable) try { wait(); } catch (InterruptedException e) {}
        data = value;
        isDataAvailable = true;
        System.out.println("Produced: " + value);
        notify();
    }

    public synchronized void consume() {
        while (!isDataAvailable) try { wait(); } catch (InterruptedException e) {}
        System.out.println("Consumed: " + data);
        isDataAvailable = false;
        notify();
    }
}

public class IPCdead{
    public static void main(String[] args) {
        SharedResource resource = new SharedResource();
        
        new Thread(() -> { for (int i = 1; i <= 5; i++) resource.produce(i); }).start();
        new Thread(() -> { for (int i = 1; i <= 5; i++) resource.consume(); }).start();

        Object lock1 = new Object(), lock2 = new Object();
        
        new Thread(() -> {
            synchronized (lock1) {
                System.out.println("Thread 1: Holding lock1");
                try { Thread.sleep(100); } catch (InterruptedException e) {}
                synchronized (lock2) { System.out.println("Thread 1: Acquired lock2"); }
            }
        }).start();

        new Thread(() -> {
            synchronized (lock2) {
                System.out.println("Thread 2: Holding lock2");
                try { Thread.sleep(100); } catch (InterruptedException e) {}
                synchronized (lock1) { System.out.println("Thread 2: Acquired lock1"); }
            }
        }).start();
    }
}

