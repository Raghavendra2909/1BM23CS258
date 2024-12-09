package SEE;
import CIE.Personal;

public class External extends Personal {
    public int[] externalMarks = new int[5]; // Public to allow access in the main file

    public External(String usn, String name, int sem, int[] externalMarks) {
        super(usn, name, sem);
        if (externalMarks.length == 5) {
            System.arraycopy(externalMarks, 0, this.externalMarks, 0, 5); // Safely copy array
        } else {
            System.out.println("Error: External marks must be for 5 courses.");
        }
    }
}
