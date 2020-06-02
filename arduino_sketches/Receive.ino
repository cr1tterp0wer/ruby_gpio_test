//GREEN_LED
#define LED_PIN 2

const String BAND       = "868500000";
const String BAUD       = "115200";
const String ADDRESS    = "1";
const String NETWORK_ID = "1";

//@Vars
String incom;
String args;

void setup() {
  
  Serial.begin( BAUD.toInt() );
  delay( 5000 ); //wait for module
  
  Serial.println( "AT" );
  delay( 1000 );

  Serial.println( args );
  delay( 2000 ); //wait for module

  args = "AT+IPR=" + BAUD;
  
  //SET BAUD
  Serial.println( args );
  delay( 2000 );

  args = "AT+BAND=" + BAND;
  
  Serial.println( args );    //Bandwidth set to 868.5MHz
  delay( 2000 );   //wait for module to respond

  args = "AT+ADDRESS=" + ADDRESS;
  Serial.println( args );   //needs to be unique
  delay( 2000 );   //wait for module to respond  

  args = "AT+NETWORKID=" + NETWORK_ID;
  Serial.println( args );   //needs to be same for receiver and transmitter
  delay( 2000 );   //wait for module to respond
  
  pinMode( LED_PIN, OUTPUT );
  digitalWrite( LED_PIN, LOW );
}

void loop() {

  // put your main code here, to run repeatedly:
  if( Serial.available() ){
      incom = Serial.readString();
      if( incom.startsWith( "+RCV=" ) ){
        Serial.println( incom + " -- RECEIVED! " );
        digitalWrite( LED_PIN, HIGH );
        delay( 100 );
        digitalWrite( LED_PIN, LOW );
      }
  }
}
