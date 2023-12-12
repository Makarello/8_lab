/*
Задача:
Приходят данные с трех источников - текстовый файл, USB, UART. Задача программы - принять данные и обработать их в соответствии с правилами
Текстовый файл содержит настройки устройства (3 числовых данных, записанных через символ ';'. Первое число - скорость передачи UART)
По USB приходят данные для обработки
По UART происходит отладка устройства и сообщения о его состоянии
	На UART приходят только два типа сообщений - D (Debug) и I (Info)

*/

#include <iostream>

#define MESSAGEFILE "123;456;789;"
#define MESSAGEUART "D some errors..."
#define MESSAGEUSB "123;456;789;"


class message_file {
public:
	std::string message = "123;456;789;";
};

class interface_reader {
protected:
	virtual void reader_init() = 0;
	virtual std::string read_from() = 0;
};

class interface_writer {
	virtual void writer_init() = 0;
	virtual void write_to(std::string S) = 0;

};

class pars_adapt {
public:
	void virtual file_adapter(message_file s) = 0;
};

class file_reader : public interface_reader {
public:
	void reader_init() {
		std::cout << "File reader init" << std::endl;
	}
	std::string read_from() {
		std::cout << "reading from file: " << MESSAGEFILE << std::endl;
		return MESSAGEFILE;
	}

};


class uart_reader : public interface_reader {
public:
	void reader_init() {
		std::cout << "UART reader init" << std::endl;
	}
	std::string read_from() {
		std::string S = MESSAGEUART;
		if (S[0] == 'D')
			std::cout << "reading from UART debug message: " << MESSAGEUART << std::endl;
		if (S[0] == 'I')
			std::cout << "reading from UART debug message: " << MESSAGEUART << std::endl;
		return MESSAGEUART;

	};
};

	class usb_reader : public interface_reader {
	public:
		void reader_init() {
			std::cout << "USB reader init" << std::endl;
		}
		std::string read_from() {
			std::cout << "reading from USB: " << MESSAGEUSB << std::endl;
			return MESSAGEUSB;
		}

	};

	class parser: public pars_adapt, message_file {
	private:
		int a = 0;
		int b = 0;
		int c = 0;

	public:
		void  file_adapter(message_file sd) {
			std::string Str = sd.message;
			std::cout << message << std::endl;
			int N = findsize(Str);
			int i = 0;
			while (Str[i] != ';') {
				a = a * 10 * (i != 0) + (int)Str[i] - 48;
				i++;
			}
			i++;
			while (Str[i] != ';') {
				b = b * 10 * (i != 0) + (int)Str[i] - 48;
				i++;
			}
			i++;
			while (Str[i] != ';') {
				c = c * 10 * (i != 0) + (int)Str[i] - 48;
				i++;
			}


		}
		int findsize(std::string Str) {
			int i = 0, count = 0;
			while (Str[i]) {
				count++;
				i++;
			}
			return count;
		}
		int get_a() { return a; };
		int get_b() { return b; };
		int get_c() { return c; };
		void set_a(int a_) { a = a_; };
		void set_b(int b_) { b = b_; };
		void set_c(int c_) { c = c_; };

	};

	class file_writer: public interface_writer {
	public:
		void writer_init() {
			std::cout << "File writing init" << std::endl;
		}
		void write_to(std::string S) {
			std::cout << "Writing to file" << S << std::endl;
		}
		void writetoUSB(std::string S) {
			std::cout << "Writing to USB" << S << std::endl;
		}
	};

	class uart_writer : public interface_writer{
		void writer_init() {
			std::cout << "Uart writing init" << std::endl;
		}
		void write_to(std::string S) {
			std::cout << "Writing to uart" << S << std::endl;
		}
	};

	class usb_writer : public interface_writer {
		void writer_init() {
			std::cout << "Usb writing init" << std::endl;
		}
		void write_to(std::string S) {
			std::cout << "Writing to usb" << S << std::endl;
		}
	};


	int main()
	{
		file_reader FR;
		uart_reader UaR;
		parser p;
		message_file m;

		m.message = "123;124;64;";
		FR.reader_init();
		p.file_adapter(m);
		UaR.reader_init();
		UaR.read_from();
		std::cout << "a = " << p.get_a() << " b = " << p.get_b() << " c = " << p.get_c() << std::endl;

	}

