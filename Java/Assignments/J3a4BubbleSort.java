import java.util.Arrays;

public class BubbleSort {
    public static <E extends Comparable<E>> void bubbleSort(E[] array) {
        int n = array.length;
        boolean swapped;
        
        do {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (array[i - 1].compareTo(array[i]) > 0) {
                    T temp = array[i - 1];
                    array[i - 1] = array[i];
                    array[i] = temp;
                    swapped = true;
                }
            }
            n--;
        } while (swapped);
    }

    public static void main(String[] args) {
        Integer[] intArray = {4, 2, 9, 1, 5};
        bubbleSort(intArray);
        System.out.println("Sorted Integer Array: " + Arrays.toString(intArray));

        String[] strArray = {"astronaut", "barista", "psycologist", "teacher"};
        bubbleSort(strArray);
        System.out.println("Sorted String Array: " + Arrays.toString(strArray));
    }
}