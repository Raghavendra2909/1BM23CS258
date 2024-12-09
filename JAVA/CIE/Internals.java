package CIE;

public class Internals {
    public int[] internalMarks = new int[5]; // Public to allow access in the main file

    public Internals(int[] internalMarks) {
        if (internalMarks.length == 5) {
            System.arraycopy(internalMarks, 0, this.internalMarks, 0, 5); // Safely copy array
        } else {
            System.out.println("Error: Internal marks must be for 5 courses.");
        }
    }
}
