//RED_LED
#define LED_PIN 2

const String BAND       = "868500000";
const String BAUD       = "115200";
const String ADDRESS    = "0";
const String NETWORK_ID = "1";

//@Vars
String outgoing;
unsigned long lastTransmission;
const int interval = 1000;
String args;

void setup() {
// put your setup code here, to run once:
  Serial.begin( BAUD.toInt() );
  delay( 2000 ); //wait for module

  Serial.println( "AT" );
  delay( 1000 );

  args = "AT+IPR=" + BAUD;
  
  //SET BAUD
  Serial.println( args );
  delay( 300 );

  args = "AT+BAND=" + BAND;
  
  Serial.println( args );    //Bandwidth set to 868.5MHz
  delay( 100 );   //wait for module to respond

  args = "AT+ADDRESS=" + ADDRESS;
  Serial.println( args );   //needs to be unique
  delay( 100 );   //wait for module to respond  

  args = "AT+NETWORKID=" + NETWORK_ID;
  Serial.println( args );   //needs to be same for receiver and transmitter
  delay( 100 );   //wait for module to respond

  //SHOW SETUP
  Serial.println( "AT+PARAMETER?" );    //@Spread_Factor, @Bandwidth
  delay( 100 );   //wait for module to respond

  Serial.println( "AT+BAND?" ); 
  delay( 100 );

  Serial.println( "AT+NETWORKID?" );   //needs to be same for receiver and transmitter
  delay( 100 );   //wait for module to respond
  
  Serial.println( "AT+ADDRESS?" );   //needs to be unique
  delay( 100 );   //wait for module to respond
  
  pinMode( LED_PIN, OUTPUT );
  digitalWrite( LED_PIN, LOW );
}

void loop() {
  
  // put your main code here, to run repeatedly:
  if( millis() > lastTransmission + interval ) {
    Serial.println( "AT+SEND=1,1,0" );
    digitalWrite( LED_PIN, HIGH );
    delay( 100 );
    digitalWrite( LED_PIN, LOW );
    lastTransmission = millis();
  }
  
}
