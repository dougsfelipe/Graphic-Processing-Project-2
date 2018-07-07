
public class pg {
	
	static float[] produtovetorial(float[] u,float[] v) {
		
		float[] vetor = new float[3];
		
		vetor[0] = (u[1]*v[2])-(u[2]*v[1]);
		vetor[1] = (u[2]*v[0])-(u[0]*v[2]);
		vetor[2] = (u[0]*v[1])-(u[1]*v[0]);
		
		return vetor;
		
		
	}
	
	
	static float produtoescalar(float[] u,float[] v) {
		
		float produtoescalar=0;
		
		for(int i = 0 ;i <3 ;i++){
		    produtoescalar = produtoescalar + (u[i]*v[i]);
		}
		return produtoescalar;
	}
	
	static float norma(float[] u) {
		
		float resu;
		
		resu = u[0]*u[0] + u[1]*u[1] + u[2]*u[2];
		resu = (float) Math.sqrt(resu);
		
		return resu;
	}
	
	
	static float[] CalcularU(float[] N,float[] V){
		
		float[] vetorU = new float[3];
		
		vetorU = produtovetorial(N, V);
		
		return vetorU;
	
	}
	
	
	static float[][] BaseMatriz(float[] N,float[] V,float[] U){
		
		float[][] Matriz = new float[3][3];
		
		for (int i = 0; i < U.length; i++) {
		Matriz[0][i] = U[i];
		}
		
		for (int i = 0; i < U.length; i++) {
			Matriz[0][i] = V[i];
			}
		
		for (int i = 0; i < U.length; i++) {
			Matriz[0][i] = N[i];
			}
		
		
		return Matriz;
		
	}
	
	
	static void Ortoganalizar(float[] N,float[] V) {
		
		float[] projecao = projecao(N, V);
		
		V[0] = V[0] - projecao[0];
		V[1] = V[1] - projecao[1];
		V[2] = V[2] - projecao[2];
		
	}
	
	
	static float[][] PrepararCamera(float[] U,float[] V,float[] N) {
		normalizar(N);
		
		Ortoganalizar(N, V);
		
		normalizar(V);
		
		CalcularU(N, V);
		
		//Camera Pronto
		
		float[][] matrizBase = BaseMatriz(N, V, U);
		
		return matrizBase;
	}
	
	
	
	
	static float[] projecao(float[] u,float[] v) {
		
		float[] vetor = new float[3];
		
		vetor[0] = ((produtoescalar(u, v))/(norma(v)*norma(v)))*v[0];
		vetor[1] = ((produtoescalar(u, v))/(norma(v)*norma(v)))*v[1];
		vetor[2] = ((produtoescalar(u, v))/(norma(v)*norma(v)))*v[2];
		
		
		return vetor;
		
	}
	
	static void normalizar(float[] u) {
		
		float n = norma(u);

		u[0] = u[0]/n;
		u[1] = u[1]/n;
		u[2] = u[2]/n;
		
	}
	
	
	static float[] NormalizarTriangulo(int[] ponto1,int[] ponto2,int[] ponto3) {
		
		float[] P1 = new float[3];
		float[] P2 = new float[3];
		
		
		P1[0]=ponto1[0]-ponto2[2];
		P1[0]=ponto1[0]-ponto2[2];
		P1[0]=ponto1[0]-ponto2[2];
		
		P2[0]=ponto1[0]-ponto3[2];
		P2[0]=ponto1[0]-ponto3[2];
		P2[0]=ponto1[0]-ponto3[2];
		
		
		
		float [] NormalTriangulo = produtovetorial(P1, P2);
		
		return NormalTriangulo;
	}
	
	
	public static void main(String[] args) {
		
		float[] u = {1,2,3};
		float[] v = {4,5,6};
		
		float[] vetor = projecao(u, v);
		
		
		for (int i = 0; i < vetor.length; i++) {
			System.out.println(vetor[i]+" ");
		}
		
		
		
	}

}
