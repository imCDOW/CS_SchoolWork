public class Point {

    int x, y;

    public Point() {
        this.x = 0;
        this.y = 0;
    }

    public Point(int x, int y) {

        this.x = x;
        this.y = y;
    }

    public boolean equals(Point other) {
        if (this.x == other.x && this.y == other.y)
            return true;
        return false;
    }

    @Override
    public int hashCode() {
        final int prime = 31;
        int result = 1;
        result = prime * result + x;
        result = prime * result + y;
        return result;
    }

}