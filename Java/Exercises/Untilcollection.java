import java.util.Collection;
public class UntilCollections {

    public interface MyList<E> extends Collection<E> {
        
        void add(int index, E e);
    
        E get(int index);
    
        int indexOf(Object e);
    
        int lastIndexOf(E e);
    
        E remove(int index);
    
        E set(int index, E e);
    
        @Override
        default boolean add(E e) {
            add(size(), e);
            return true;
        }
    
        @Override
        default boolean isEmpty() {
            return size() == 0;
        }
    
        @Override
        default boolean remove(Object e) {
            int index = indexOf(e);
            if (index >= 0) {
                remove(index);
                return true;
            }
            return false;
        }
    
        @Override
        default boolean containsAll(Collection<?> c) {
            for (Object e : c) {
                if (!contains(e)) {
                    return false;
                }
            }
            return true;
        }
    
        @Override
        default boolean addAll(Collection<? extends E> otherList) {
            boolean changed = false;
            for (E element : otherList) {
                if (add(element)) {
                    changed = true;
                }
            }
            return changed;
        }
    
        @Override
        default boolean removeAll(Collection<?> c) {
            boolean changed = false;
            for (Object ob : c) {
                if (remove(ob)) {
                    changed = true;
                }
            }
            return changed;
        }
    
        @Override
        default boolean retainAll(Collection<?> c) {
            boolean changed = false;
            int index = size() - 1;
            while (index >= 0) {
                Object ob = get(index);
                if (c.contains(ob)) {
                    remove(index);
                    changed = true;
                }
                index--;
            }
            return changed;
        }
    
        @Override
        default Object[] toArray() {
            Object[] array = new Object[size()];
            for (int i = 0; i < size(); i++) {
                array[i] = get(i);
            }
            return array;
        }
    
        @Override
        default <T> T[] toArray(T[] array) {
            if (array.length < size()) {
                array = (T[]) new Object[size()];
            }
            for (int i = 0; i < size(); i++) {
                array[i] = (T) get(i);
            }
            return array;
        }
    } 
}
