#include "Firma.h"
#include <NTL/ZZ.h>
#include "fstream"
#include "funciones.h"
using namespace std;
using namespace sf;

Firma:: Firma(){
  this->e=1;
  this->N=121;
  this->d=1;

}
Firma::Firma(int bit)
{

    this->n_bit=bit;
    generar_clave();
}
Firma::Firma(ZZ e,ZZ n)
{
    this->e_b=e;
    this->N_b=n;
    //this->n_bit=b;
    //generar_clave();
}
void Firma::generar_clave(){

    //this->n_bit=bit;

    this->p=GenPrime_ZZ(n_bit);
    this->q=GenPrime_ZZ(n_bit);
    this->N=p*q;
    this->phi_n=(p-1)*(q-1);
    this->e=mat.generar_aleatorio(n_bit);

    while(mat.mcd(e,phi_n)!=1 && e<phi_n )
        this->e=mat.generar_aleatorio(n_bit);
    this->d=mat.mod(mat.eExtendido(e,phi_n),phi_n);

    cout<<"valor de N:"<<N<<endl;
	cout<<"clave publica e: "<<e<<endl;
	cout<<"clave privada d: "<<d<<endl;

    ofstream Directorio ;
	ofstream clavesPrivadas;
	Directorio.open("Directorio publico.txt");
	clavesPrivadas.open("claves Privadas.txt");

    Directorio << "publico:THE LIFE IS  N "<< N << "\nClave e: "<< e << endl;
	clavesPrivadas << "p: "<< p <<"\n"<< "q: "<< q <<"\n"<< "N: "<< N <<"\n"<< "phi_n: "<< phi_n <<"\n"<< "e: "<< e <<"\n"<< "d: "<< d << endl ;

	clavesPrivadas.close();
	Directorio.close();


}
string Firma::ZZ_a_string(ZZ n)
{
    stringstream  ss;
    ss<<n;
    string  numero;
    ss>>numero;
    return numero;
}
ZZ Firma::string_a_ZZ(string algo)
{stringstream sst(algo);
 ZZ Num;
 sst>>Num;
 return Num;
}
string Firma::Int_a_string(int a)
{
    stringstream stream;
    stream<<a;
    string b=stream.str();
    return b;
}
string Firma::completar(string name,int a)
{   while(a>0)
         {name.insert(0,"0");
         a=a-1;}
    return name;
}
int Firma::string_a_int(string n)
{
    stringstream ss(n);
    int numero;
    ss>>numero;
    return numero;
}
string Firma::firmar(){
    Image img;
    img.loadFromFile("imagenes/logo.jpg");
    Vector2<int>mm(img.getSize());cout<<mm.x<<" x "<<mm.y<<endl;
    string answer;int dif;
    vector<int>k;
    for(int i=0;i<mm.x;i++){
        for(int e=0;e<mm.y;e++)
        {
            Color c_rgb=img.getPixel(i,e);
            k.push_back(c_rgb.r);
            k.push_back(c_rgb.g);
            k.push_back(c_rgb.b);
        }
    }
    int tam=k.size();
    cout<<tam<<endl;
    for(int i=0;i<tam;i++)//formalizamos
    {
        string tmp;
        tmp=to_string(k[i]);
        dif=3-tmp.size();
        if(dif!=0)
            tmp=completar(tmp,dif);
        answer=answer+tmp;
    }
    return answer;
}
string Firma::Rubrica(){
    string rubrica1=firmar(),separ,rub,bloques,blo,nn=ZZ_a_string(N);
    int inicio=0,tmi_n=nn.size()-1,t=rubrica1.size();
    ZZ rubrica;
    while(rubrica1.size()){
        blo=rubrica1.substr(0,tmi_n);
        int tt=tmi_n-blo.size();
        if(tt!=0){
            while(tt>0)
            {
                blo=blo+'0';
                tt--;
            }
        }
        bloques=bloques+blo;
        rubrica1.erase(0,tmi_n);
    }
    while(bloques.size())
    {
        blo="";
       separ=bloques.substr(inicio,tmi_n);
       rubrica=mat.exp(string_a_ZZ(separ),d,N);
       blo=ZZ_a_string(rubrica);
       int pt=1+tmi_n-blo.size();
       if(pt!=0){
        blo=completar(blo,pt);
       }
       rub=rub+blo;
       bloques.erase(0,tmi_n);
    }

    return rub;
}
string Firma::firmo(){
    string bloc,bloque,bb=Rubrica(),n_l=ZZ_a_string(this->N_b);
    int inicio=0,t=bb.size();ZZ expo;
    int tn=n_l.size()-1;
    cout<<e_b<<"         "<<N_b<<endl;
    while(bb.size()){
        bloc=bb.substr(0,tn);
        expo=mat.exp(string_a_ZZ(bloc),e_b,N_b);//de usted y no de mi
        bloc=ZZ_a_string(expo);
        int tn_el=(1+tn)-bloc.size();
        if(tn_el!=0)
            bloc=completar(bloc,tn_el);
        bloque=bloque+bloc;
        bb.erase(0,tn);
    }
    return bloque;
}
string Firma::recibom(string letra){

    string a,b,c=ZZ_a_string(N),envio,nn_re=ZZ_a_string(N_b);
    int tamm=c.size();ZZ prime,rubb;
    int ini=0;
    for(int i=tamm;i<letra.size();i+=tamm){
        b=letra.substr(ini,i);
        prime=mat.exp(string_a_ZZ(b),d,N);
        b=ZZ_a_string(rubb);
        int tam=(tamm-1)-b.size();
        if(tam!=0){
           b=completar(b,tam);
        }
        a=a+b;
    }
    int n_r=nn_re.size();
    ZZ rec;b="";
    while(a.size()){
        b=a.substr(0,n_r);
        rec=mat.exp(string_a_ZZ(b),e_b,N_b);
        b=ZZ_a_string(rec);
        int tamanio=(n_r-1)-b.size();
        if(tamanio!=0)
            b=completar(b,tamanio);
        envio=envio+b;
    }
    return envio;
}
bool Firma::numero(char a){
    int num=static_cast<int>(a);
    return(48<=num && num<=57);
}
void Firma::confirma(string pex){
    vector<int>kk;

    int con=0;string numstr;
    for(int i=3;i<pex.size();i+=3,con++){
        numstr=pex.substr(0,i);
        int n=string_a_int(numstr);
        kk.push_back(n);
    }
    // Impresion
    for(int i=0;i<kk.size();i++){
        cout<<kk[i]<<"  ";
    }
    sf::RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo Game");
    sf::Event event;
    sf::Image image;
    image.create(640, 480);
    int a=0,b=1,c=2;
    for (int y = 0; y <64; y++){
        for (int x = 0; x < 64; x++){
            Color p(kk[a],kk[b],kk[c]);
            image.setPixel(x,y,p);
            a+=3;b+=3;c+=3;
        }
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite(texture);

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
// SHOW IMAGE RESULT
void Firma::showImageResult()
{
    RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo");

    Event event;

    Image image;
    int d_x = 16,d_y =16;
    //image.create(d_x, d_y, sf::Color::Black);
    image.create(d_x, d_y);

    int a = 0, b = 1, c = 2;
    for (int x = 0; x < d_x; x++){

        for (int y = 0; y < d_y; y++){
            Color Pixel(r[a],r[b],r[c]);
            image.setPixel(x, y, Pixel);
             a+=3;b+=3;c+=3;
        }
        //cout<<"mostrando"<<endl;
  }

  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite(texture);

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
//SHOW IMAGE
void Firma::showImage(int d_x,int d_y)
{
    RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo");

    Event event;

    Image image;
    image.create(d_x, d_y, sf::Color::Black);


    int a = 0, b = 1, c = 2;
    for (int x = 0; x < d_x; x++){

        for (int y = 0; y < d_y; y++){
            Color Pixel(g[a],g[b],g[c]);
            image.setPixel(x, y, Pixel);
             a+=3;b+=3;c+=3;
        }
  }

  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite(texture);

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
// LOAD IMAGE
string Firma::loadImg(int alto,int ancho)
{
    Image img;
    img.loadFromFile(nomImag);
    string answer;
    for(int i=0; i<alto; i++){
        for(int e = 0; e<ancho;e++){
            Color c_rgb = img.getPixel(i,e);
            g.push_back(c_rgb.r);g.push_back(c_rgb.g);
            g.push_back(c_rgb.b);
        }
    }
    int tam = g.size();
    for(int i=0;i<tam;i++){
        string tmp;
        tmp = to_string(g[i]);//cout << g[i]<<"   ";
        tmp = completarC(tmp,3);
        answer +=tmp;
    }
    //escribiR("pixeles.txt",answer);
    //cout<<"PIXELES DE LA IMAGEN :"<<answer<<endl;
    return answer;
}

//mio
string Firma::firmaDigital(){
    //this->e_b = E_B;
    //this->N_b = N_B;
    //string rgb = loadImg(64,64);
    string rgb = loadImg(16,16);
    //ejemplo  string rgb = loadImg(3,3);
    int cif_N= ZZ_a_string(N).size();
    cif_N -=1;// los bloques para la rubrica seran de tamaño cif_N
    rgb = completarC_Atras(rgb,cif_N);

    string Firma,r_firma, operarRubrica,rubrica;

    ZZ OR;
    //Operar rubrica
    while(rgb.size()>0){
        OR = string_a_ZZ(rgb.substr(0,cif_N));
        rgb.erase(0,cif_N);
        OR = exp_modular(OR,d,N);
        //cout<<"r: "<< OR <<endl;
        rubrica = completarC(ZZ_a_string(OR),cif_N+1);
        operarRubrica += rubrica;
    }
    // RECUPERAR CLAVES DE BOB

    int b = ZZ_a_string(N_b).size()-1;
    operarRubrica =completarC_Adelante(operarRubrica,b);
    int cif_Nb = b+1;
    string r;
    //Firmar la rurica
    while(operarRubrica.size()>0){

        r = operarRubrica.substr(0,b);
        F = exp_modular(string_a_ZZ(r),e_b,N_b);
        Firma += completarC(ZZ_a_string(F),cif_Nb);

        operarRubrica.erase(0,b);
    }
    //cout <<"Firma: "<<endl<< Firma<<endl;
    cout<<endl;
    return Firma;

}
//GUARDAR PIXELES EN G
void Firma::guardarR(string pixeles){

    int pixel;
    while(pixeles.size()>0){
            pixel = atoi(pixeles.substr(0,3).c_str());
            pixeles.erase(0,3);
            r.push_back(pixel);
    }
    //cout <<"guardo"<<endl;
}
//OPTENER RUBRICA

void Firma::obtenerRubica(string firma){

    int cif_Na = ZZ_a_string(N_b).size();//SIENDO YO B COMO A
    string Rubrica;
    string I_Firma;
    string finalS;
    ZZ rubrica;
    string n_st=ZZ_a_string(N_b);
    while(firma.size()>0){
        rubrica = string_a_ZZ(firma.substr(0,cif_Na));
        firma.erase(0,cif_Na);
        I_Firma = ZZ_a_string(exp_modular(rubrica,d,N));
        I_Firma = completarC(I_Firma,cif_Na-1);
        finalS += I_Firma;
    }
    //RECUPERAR CLAVES DE Alice emisor
    int cif_Nb = ZZ_a_string(N_b).size();
    //Operar la rubrica
    string recuperar;

    finalS = completarC_Adelante(finalS,cif_Nb);

    while(finalS.size()>0){
        rubrica = string_a_ZZ(finalS.substr(0,cif_Nb));
        finalS.erase(0,cif_Nb);
        I_Firma = ZZ_a_string(exp_modular(rubrica,e_b,N_b));
        I_Firma = completarC(I_Firma,cif_Nb-1);
        recuperar += I_Firma;
    }
    cout<< "recuperado"<<recuperar<<endl;
   // escribiR("descifrado.txt",recuperar);
    guardarR(recuperar);
    showImageResult();
    //showImage(64,64);
}

/*
#include "Firma.h"
#include <fstream>
#include <sstream>
#include "funciones.h"
#include <iostream>
#include <NTL/ZZ.h>
#include <vector>
#include <string>
#include <cstdlib>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace NTL;
using namespace std;

Firma::Firma(){
    this->N_b = 28199;
    this->e_b = 31;
    this->d_b = 22471;

    this->N = 29651;
    this->e = 169;
    this->d = 10057;
    this->p = 199;
    this->q = 149;
    cout<< "p: "<< p <<"\n"<< "q: "<< q <<"\n"<< "N: "<< N <<"\n"<< "phi_N: "<< phi_N <<"\n"<< "e: "<< e <<"\n"<< "d: "<< d << endl ;
    cout<<"\n"<< "N_B: "<< N_b <<"\n"<< "e_b: "<< e_b <<"\n"<< "d_b: "<< d_b<< endl ;
}
Firma::Firma(int n_bits)
{
     this->n_bits = n_bits;
    generar_claves();
}
Firma::Firma(ZZ d_B,ZZ N_B)
{
    this->d_b=d_B;
    this->N_b=N_B;
}
*/
/*
void Firma::generar_claves(){

    this->p=43319;
    this->q=  44753;
    this->N= 1938655207;
    this->phi_N=(p-1)*(q-1);
    this->e = 12389 ;*/
/*
    this->p=GenPrime_ZZ(n_bits);
    this->q=GenPrime_ZZ(n_bits);
    this->N=p*q;
    this->phi_N=(p-1)*(q-1);
    this->e = generar_aleatorio(n_bits);
    while(euclides(e,phi_N)!=1){
        this->e= generar_aleatorio(n_bits);
    }
    this->d = mod( extendido(e,phi_N),phi_N);
	cout<< "p: "<< p <<"\n"<< "q: "<< q <<"\n"<< "N: "<< N <<"\n"<< "phi_N: "<< phi_N <<"\n"<< "e: "<< e <<"\n"<< "d: "<< d << endl ;

}
string Firma::firmaDigital(ZZ N_B,ZZ E_B){
    string rgb = loadImg(64,64);
    //ejemplo  string rgb = loadImg(3,3);
    int cif_Na= ZZ_a_string(N_B).size();
    cif_Na -=1;// los bloques para la rubrica seran de tamaño cif_N
    rgb = completarC_Atras(rgb,4,cif_Na);

    string Firma,r_firma, operarRubrica,rubrica;

    ZZ OR;
    //Operar rubrica
    while(rgb.size()>0){
        OR = string_a_ZZ(rgb.substr(0,cif_Na));
        rgb.erase(0,cif_Na);
        OR = exp_modular(OR,d,N);
        //cout<<"r: "<< OR <<endl;
        rubrica = completarC(ZZ_a_string(OR),cif_Na);
        operarRubrica += rubrica;
    }
    int b = ZZ_a_string(N_B).size()-1;
    int cif_Nb = b+1;
    string r;
    //Firmar la rurica
    while(operarRubrica.size()>0){

        r = operarRubrica.substr(0,b);
        F = exp_modular(string_a_ZZ(r),E_B,N_B);
        Firma += completarC(ZZ_a_string(F),cif_Nb);

        operarRubrica.erase(0,b);
    }
    cout <<"Firma: "<<endl<< Firma<<endl;
    cout<<endl;
    return Firma;

}
string Firma::loadImg(int alto,int ancho)
{
    Image img;
    img.loadFromFile(nomImag);
    string answer;
    for(int i=0; i<alto; i++){
        for(int e = 0; e<ancho;e++){
            Color c_rgb = img.getPixel(i,e);
            g.push_back(c_rgb.r);g.push_back(c_rgb.g);
            g.push_back(c_rgb.b);
        }
    }
    int tam = g.size();
    for(int i=0;i<tam;i++){
        string tmp;
        tmp = to_string(g[i]);//cout << g[i]<<"   ";
        tmp = completarC(tmp,3);
        answer = answer+tmp;
    }//cout<<"PIXELES DE LA IMAGEN :"<<answer<<endl;
    return answer;
}
void Firma::showImage(int d_x,int d_y)
{
    RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo");

    Event event;

    Image image;
    image.create(d_x, d_y, sf::Color::Black);


    int a = 0, b = 1, c = 2;
    for (int x = 0; x < d_x; x++){

        for (int y = 0; y < d_y; y++){
            Color Pixel(g[a],g[b],g[c]);
            image.setPixel(x, y, Pixel);
             a+=3;b+=3;c+=3;
        }
  }

  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite(texture);

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
void Firma::showImageResult()
{
    RenderWindow renderWindow(sf::VideoMode(640, 480), "Demo");

    Event event;

    Image image;
    int d_x = 64,d_y =64;
    //image.create(d_x, d_y, sf::Color::Black);
    image.create(d_x, d_y, sf::Color::Black);

    int a = 0, b = 1, c = 2;
    for (int x = 0; x < d_x; x++){

        for (int y = 0; y < d_y; y++){
            Color Pixel(r[a],r[b],r[c]);
            image.setPixel(x, y, Pixel);
             a+=3;b+=3;c+=3;
        }
        cout<<"mostrando"<<endl;
  }

  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite(texture);

  while (renderWindow.isOpen()){
    while (renderWindow.pollEvent(event)){
      if (event.type == sf::Event::EventType::Closed)
        renderWindow.close();
    }

    renderWindow.clear();
    renderWindow.draw(sprite);
    renderWindow.display();
  }
}
void Firma::guardarR(string pixeles){

    int pixel;
    while(pixeles.size()>0){
            pixel = atoi(pixeles.substr(0,3).c_str());
            pixeles.erase(0,3);
            r.push_back(pixel);
    }
    cout <<"guardo"<<endl;
}
void Firma::obtenerRubica(string firma,ZZ E_A,ZZ N_A){

    //para probar
    //this->d_b = ZZ(1675);
    //this->N_b = ZZ(1961);
    //int cif_Nb = ZZ_a_string(N_b).size();
    cout<< "Obtencion de la imagen"<<endl;
    int cif_Nb = ZZ_a_string(N).size();
    string Rubrica;
    string I_Firma;
    string finalS;
    ZZ rubrica;
    string n_st=ZZ_a_string(N);
    while(firma.size()>0){
        cout<<"bucle"<<endl;
        rubrica = string_a_ZZ(firma.substr(0,n_st.size()));
        firma.erase(0,n_st.size());
        I_Firma = ZZ_a_string(exp_modular(rubrica,d,N));
        I_Firma = completarC(I_Firma,n_st.size()-1);
        finalS += I_Firma;
    }
    int cif_Na = ZZ_a_string(N_A).size();
    cout<< "finals :"<<finalS<<endl;
    //Operar la rubrica
    string recuperar;
    while(finalS.size()>0){
        rubrica = string_a_ZZ(finalS.substr(0,cif_Na));
        firma.erase(0,cif_Na);
        I_Firma = ZZ_a_string(exp_modular(rubrica,E_A,N_A));
        I_Firma = completarC(I_Firma,cif_Na-1);
        recuperar += I_Firma;
    }
    guardarR(recuperar);
    showImageResult();
    //showImage(64,64);
}
*/
