
public class Aplicacion {
  public static void main(String[] args) {
       double h=1;       //paso
        double w0=1.0;       //frecuencia propia oscilaciones libres
        double t=1000.0;        //resolver la e. d. hasta este instante
//Situación inicial
        double x0=-1.0;      //posición inicial
        double v0=0.0;      //velocidad inicial
        Estado e=new Estado(0.0, x0, v0);

//oscilaciones libres
        System.out.println("Oscilaciones libres");
        Oscilador os=new Oscilador(h, w0);
        for(int i=0; i<t/h; i++){
              os.resolver(e);
              System.out.println(e.x+" "+e.v+" "+i*h);
        }
        
  }
}