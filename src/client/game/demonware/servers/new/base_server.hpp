#pragma once
#include <utils/cryptography.hpp>

class base_server
{
public:
	base_server(std::string name)
		: name_(std::move(name))
	{
		this->address_ = utils::cryptography::jenkins_one_at_a_time::compute(this->name_);
	}

	base_server(base_server&&) = delete;
	base_server(const base_server&) = delete;
	base_server& operator=(base_server&&) = delete;
	base_server& operator=(const base_server&) = delete;

	virtual ~base_server() = default;

	const std::string& get_name() const
	{
		return this->name_;
	}

	uint32_t get_address() const
	{
		return this->address_;
	}

	virtual void frame()
	{
	}

	virtual bool pending_data()
	{
		return false;
	}

private:
	std::string name_;
	std::uint32_t address_ = 0;
};
