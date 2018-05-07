public class Oscilador extends RungeKutta{
    protected double w0;       //frecuencia angular
    public Oscilador(double h, double w0){
        super(h);
        this.w0=w0;
    }
    public double f(double x, double v, double t){
        return (-0.15*v +x -Math.pow(x,3) +0.3*Math.cos(w0*t));
    }
}