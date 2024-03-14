import java.util.Comparator;
import java.util.Arrays;

public class BubbleSortWithComparator {
    public static <E> void bubbleSortWithComparator(E[] array, Comparator<E> comparator) {
        int n = array.length;
        boolean swapped;
        
        do {
            swapped = false;
            for (int i = 1; i < n; i++) {
                if (comparator.compare(array[i - 1], array[i]) > 0) {
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
        Comparator<Integer> intComparator = Integer::compare;
        bubbleSortWithComparator(intArray, intComparator);
        System.out.println("Sorted Integer Array: " + Arrays.toString(intArray));

        String[] strArray = {"astronaut", "barista", "psycologist", "teacher"};
        Comparator<String> strComparator = String.CASE_INSENSITIVE_ORDER;
        bubbleSortWithComparator(strArray, strComparator);
        System.out.println("Sorted String Array: " + Arrays.toString(strArray));
    }
}