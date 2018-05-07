
public abstract class RungeKutta {
      double h;
  public RungeKutta(double h) {
     this.h=h;
  }
  public void setPaso(double h){
        this.h=h;
  }
  public void resolver(Estado e){
//variables auxiliares
        double k1, k2, k3, k4;
        double l1, l2, l3, l4;
//estado en el instante t
        double x=e.x;
        double v=e.v;
        double t=e.t;

            k1=h*v;
            l1=h*f(x, v, t);
            k2=h*(v+l1/2);
            l2=h*f(x+k1/2, v+l1/2, t+h/2);
            k3=h*(v+l2/2);
            l3=h*f(x+k2/2, v+l2/2, t+h/2);
            k4=h*(v+l3);
            l4=h*f(x+k3, v+l3, t+h);
            x+=(k1+2*k2+2*k3+k4)/6;
            v+=(l1+2*l2+2*l3+l4)/6;
            t+=h;
//estado en el instante t+h
        e.t=t;
        e.x=x;
        e.v=v;
    }
    abstract public double f(double x, double y, double t);
}