=begin
AT+IPR=115200 #BAUD RATE
AT+BAND=868500000
AT+ADDRESS=1
AT+NETWORKID=1
=end
#BAUD bits/second
# TX serial is on "/dev/ttyAMA0"
#

module GPIO
  require 'rpi_gpio'
  LED_PIN_NUM = 29
  UART0_TXD_PIN_NUM = 8
  REYAX_ARGS = {
    IPR: 115200,
    BAND: 868500000,
    ADDRESS: 1,
    NETWORKID: 1
  }.freeze

  class GPIO_REYAX

    def initialize(led_on = false)
      @gpio = RPi::GPIO
      @gpio.set_numbering :board
      @gpio.clean_up
      @gpio.setup LED_PIN_NUM, as: :output, initialize: :low
      @gpio.setup UART0_TXD_PIN_NUM, as: :output
    end
    
    def broadcast
      @previous = Time.now()
      while true do 
#        blink LED_PIN_NUM
        @now = Time.now()
        change = @now - @previous
        @previous = @now
        next if change < 0.00010416
        puts change
      end
    end

    def blink( pin )
      return if pin.nil?
      @gpio.high?(pin) ? @gpio.set_low(pin) : @gpio.set_high(pin)
    end
  end
end


gpio = GPIO::GPIO_REYAX.new
gpio.broadcast
