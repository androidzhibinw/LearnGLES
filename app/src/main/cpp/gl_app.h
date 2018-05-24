class GLBaseApp
{
public:
    GLBaseApp(){};
    virtual ~GLBaseApp(){};
    virtual void Initialize()=0;
    virtual void Render() = 0;
    virtual void ShutDown()=0;
};

extern GLBaseApp* CreateGLApp();