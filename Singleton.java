import java.util.ArrayList;

public class Singleton{
	
private ArrayList<String> List = null;
	
private Singleton singletonInstance = new Singleton();
	
public Singleton wezInstance(){
		return singletonInstance;}
	
	
public ArrayList<String> wezLista(){
		return List;}
	
public void dodaj(String elemencik){
		List.add(elemencik);}
	
	public static void main(String[] args) {
		

	}

}
