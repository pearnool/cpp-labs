#include <iostream>

struct bus
{
    std::string bus_number;
    std::string bus_driver;
    std::string route;
    bus *next;

    bus(const std::string &bus_number, const std::string &bus_driver, const std::string &route)
        : bus_number(bus_number), bus_driver(bus_driver), route(route), next(nullptr) {}
};

struct buslist
{

    bus *head;

    buslist() : head(nullptr) {}

    void append(const std::string &bus_number, const std::string &bus_driver, const std::string &route)
    {
        bus *new_node = new bus(bus_number, bus_driver, route);

        if (head == nullptr)
            head = new_node;
        else
        {
            bus *tmp = head;
            while (tmp->next != nullptr)
                tmp = tmp->next;
            tmp->next = new_node;
        }
    }

    void print_info(const bus *bus) const
    {
        std::cout << bus->bus_number << std::endl;
        std::cout << bus->bus_driver << std::endl;
        std::cout << bus->route << std::endl;
    }

    void print_parked() const
    {
        std::cout << "parked buses: " << std::endl;
        bus *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->route == "parked")
                print_info(tmp);
            tmp = tmp->next;
        }
    }

    void print_en_route() const
    {
        std::cout << "buses en route: " << std::endl;
        bus *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->route != "parked")
                print_info(tmp);
            tmp = tmp->next;
        }
    }

    void change_route(std::string bus_number, std::string route)
    {
        bus *tmp = head;

        while (tmp != nullptr)
        {
            if (tmp->bus_number == bus_number)
                tmp->route = route;
            tmp = tmp->next;
        }
    }

    void park(std::string bus_number)
    {
        bus *tmp = head;
        while (tmp != nullptr)
        {
            if (tmp->bus_number == bus_number)
                tmp->route = "parked";
            tmp = tmp->next;
        }
    }
};

int main()
{
    buslist buses;

    buses.append("A32BM", "Johnson", "65");
    buses.append("A302FS", "Stevenson", "parked");
    buses.append("BB3320", "Peterson", "parked");

    buses.print_parked();
    buses.print_en_route();

    buses.change_route("A32BM", "43");
    buses.print_en_route();

    buses.park("A32BM");
    buses.print_parked();
}