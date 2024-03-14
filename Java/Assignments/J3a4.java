import java.util.Comparator;
public class BubbleSort {


    public static <E extends Comparable<E>> void bubbleSortComparable(E[] array) {
        int n = array.length;
        boolean swapped;
        
        do {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (array[i - 1].compareTo(array[i]) > 0) {
                    // Swap elements at index i-1 and i
                    T temp = array[i - 1];
                    array[i - 1] = array[i];
                    array[i] = temp;
                    swapped = true;
                }
            }
            n--;
        } while (swapped);
    }

    
    public static <E> void bubbleSortWithComparator(E[] array, Comparator<E> comparator) {
        int n = array.length;
        boolean swapped;
        
        do {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (comparator.compare(array[i - 1], array[i]) > 0) {
                    // Swap elements at index i-1 and i
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

        Integer[] intArray = {5, 2, 9, 1, 5, 6};
        bubbleSortComparable(intArray);
        System.out.println("Sorted Integer Array (Comparable): ");
        for (Integer num : intArray) {
            System.out.print(num + " ");
        }
        System.out.println();

        String[] strArray = {"apple", "banana", "cherry", "date", "fig"};
        Comparator<String> strLengthComparator = Comparator.comparing(String::length);
        bubbleSortWithComparator(strArray, strLengthComparator);
        System.out.println("Sorted String Array (Comparator - Length): ");
        for (String str : strArray) {
            System.out.print(str + " ");
        }
        System.out.println();
    }
}

