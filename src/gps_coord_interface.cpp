class gps_coord_interface
{
private:
    /* data */
public:
    gps_coord_interface(/* args */);
    ~gps_coord_interface();

    bool coords_correct();
};

gps_coord_interface::gps_coord_interface(/* args */)
{
}

gps_coord_interface::~gps_coord_interface()
{
}

bool gps_coord_interface::coords_correct()
{
    return true;
}