=begin
AT+IPR=115200
AT+BAND=868500000
AT+ADDRESS=1
AT+NETWORKID=1
=end

module GPIO
  require 'rpi_gpio'
  PIN_NUM = 5

  class GPIO_TEST

    def initialize(led_on = false)
      @gpio = RPi::GPIO
      @gpio.set_numbering :bcm
      @gpio.clean_up
      @gpio.setup PIN_NUM, as: :output, initialize: :low
    end

    def blink
      while true do 
        sleep 1
        if @gpio.high?(PIN_NUM)
          puts 'HIGH'
        else
          puts 'LOW'
        end
        @gpio.high?(PIN_NUM) ? @gpio.set_low(PIN_NUM) : @gpio.set_high(PIN_NUM)
      end
    end
  end
end


gpio = GPIO::GPIO_TEST.new
gpio.blink
