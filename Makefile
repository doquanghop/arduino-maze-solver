# Cấu hình thư viện và đường dẫn
ARDUINO_DIR = /usr/share/arduino
BOARD = uno
PORT = /dev/ttyUSB0

# Các tệp nguồn
SRC = main.cpp

# Tệp nhị phân đầu ra
OUT = main.hex

# Lệnh biên dịch
CC = $(ARDUINO_DIR)/hardware/tools/avr/bin/avr-g++
CFLAGS = -mmcu=atmega328p -Os -g

# Các bước biên dịch
all: $(OUT)

$(OUT): $(SRC)
	$(CC) $(CFLAGS) -o $(OUT) $(SRC)

upload: $(OUT)
	# Lệnh để tải tệp nhị phân lên Arduino
	avrdude -c arduino -p m328p -P $(PORT) -b 115200 -U flash:w:$(OUT):i

clean:
	rm -f $(OUT)

