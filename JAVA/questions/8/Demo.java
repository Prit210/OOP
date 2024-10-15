//Question 8

abstract class Figure {
    protected double r, a, v, pi = 3.1428;

    public abstract void calcArea();
    public abstract void calcVolume();
    public abstract void dispArea();
    public abstract void dispVolume();
}

class Cone extends Figure {
    private double s, h;

    public Cone(double r, double s, double h) {
        this.r = r;
        this.s = s;
        this.h = h;
    }

    @Override
    public void calcArea() {
        a = (pi * r * s) + (pi * r * r);
    }

    @Override
    public void calcVolume() {
        v = (pi * r * r * h) / 3;
    }
    
    @Override
    public void dispArea() {
        System.out.println("Cone Area: " + a);
    }
    
    @Override
    public void dispVolume() {
        System.out.println("Cone Volume: " + v);
    }
}

class Sphere extends Figure {
    public Sphere(double r) {
        this.r = r;
    }
    
    @Override
    public void calcArea() {
        a = 4 * pi * r * r;
    }
    
    @Override
    public void calcVolume() {
        v = (4 * pi * r * r * r) / 3;
    }
    
    @Override
    public void dispArea() {
        System.out.println("Sphere Area: " + a);
    }
    
    @Override
    public void dispVolume() {
        System.out.println("Sphere Volume: " + v);
    }
}

class Cylinder extends Figure {
    private double h;

    public Cylinder(double r, double h) {
        this.r = r;
        this.h = h;
    }
    
    @Override
    public void calcArea() {
        a = (2 * pi * r * r) + (2 * pi * r * h);
    }
    
    @Override
    public void calcVolume() {
        v = pi * r * r * h;
    }
    
    @Override
    public void dispArea() {
        System.out.println("Cylinder Area: " + a);
    }
    
    @Override
    public void dispVolume() {
        System.out.println("Cylinder Volume: " + v);
    }
}

public class Demo {
    public static void main(String[] args) {
        Cone cone = new Cone(3, 5, 7);
        cone.calcArea();
        cone.calcVolume();
        cone.dispArea();
        cone.dispVolume();

        Sphere sphere = new Sphere(4);
        sphere.calcArea();
        sphere.calcVolume();
        sphere.dispArea();
        sphere.dispVolume();

        Cylinder cylinder = new Cylinder(2, 10);
        cylinder.calcArea();
        cylinder.calcVolume();
        cylinder.dispArea();
        cylinder.dispVolume();
    }
}
