/*************************************************************************
#	> File Name:server.cpp
#	> Author: jarven
#	> Mail: whuaw@aliyun.com
#	> Created Time: 2019年08月13日 星期二 17时23分24秒
 ************************************************************************/

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using namespace std;
using namespace boost::asio;

typedef	boost::shared_ptr<ip::tcp::socket>	socket_ptr;

int main(int argc, char* argv[])  
{
	try
	{
		io_service m_io_service;
		ip::tcp::acceptor acceptor(m_io_service,
				ip::tcp::endpoint(ip::tcp::v4(), 8080));

		for(; ;)
		{
			boost::system::error_code ec;

			ip::tcp::socket socket_server(m_io_service);

			acceptor.accept(socket_server);

			cout <<  socket_server.remote_endpoint().address() << endl;

			//socket_server.write_some();
			if(ec)
			{
				cout << boost::system::system_error(ec).what() << endl;
			}
		}

	}
	catch(std::exception &e)
	{
		cout << e.what()<< endl;
	}
	return 0;
}
