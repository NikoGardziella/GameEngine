#pragma once
#include <string>


namespace GameEngine{
    
    class Shader
    {
    public:
        Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
        ~Shader();
    void Bind() const;
    void unbind() const;
   
    private:
        u_int32_t m_renderID;
    };

    
}
