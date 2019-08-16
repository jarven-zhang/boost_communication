/*************************************************************************
#	> File Name:client.cpp
#	> Author: jarven
#	> Mail: whuaw@aliyun.com
#	> Created Time: 2019年08月14日 星期三 04时10分46秒
 ************************************************************************/

#include<iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

//客户端
int main(void)
{
	io_service iosev;
	// socket对象
	ip::tcp::socket socket(iosev);
	// 连接端点，这里使用了本机连接，可以修改IP地址测试远程连接
	ip::tcp::endpoint ep(ip::address_v4::from_string("127.0.0.1"), 8080);
	// 连接服务器
	boost::system::error_code ec;
	socket.connect(ep, ec);
	// 如果出错，打印出错信息
	if (ec)
	{
		std::cout << boost::system::system_error(ec).what() << std::endl;
		return -1;
	}
	// 接收数据
	char buf[100];
	size_t len = socket.read_some(buffer(buf), ec);
	std::cout.write(buf, len);

	return 0;
}

