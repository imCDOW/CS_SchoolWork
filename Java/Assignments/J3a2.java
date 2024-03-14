import java.util.Arrays;

public class GenericLinearSearch {

    public static void main(String[] args) {
        Integer[] list = createIntegerArray(20);
        System.out.println(linearSearch(list, 1));
        System.out.println(linearSearch(list, 10));
        System.out.println(linearSearch(list, 30));
    }

    public static Integer[] createIntegerArray(int size) {
        Integer[] array = new Integer[size];
        for (int i = 0; i < size; i++) {
            array[i] = i;
        }
        return array;
    }

    public static <E extends Comparable<E>> int linearSearch(E[] list, E value) {
        for (int i = 0; i < list.length; i++) {
            if (list[i].compareTo(value) == 0) {
                return i;
            }
        }
        return -1;
    }
}