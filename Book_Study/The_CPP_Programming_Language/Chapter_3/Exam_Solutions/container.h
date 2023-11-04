class Container{
    public:
        virtual double& operator[](int) =0;
        virtual std::size_t size() const = 0;
        virtual ~Container() {}
};