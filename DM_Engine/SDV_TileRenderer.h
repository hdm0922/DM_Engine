//#pragma once
//#include "DM_RenderComponent.h"
//#include "SDV_Framework.h"
//
//
//
//
//
//namespace SDV
//{
//    class TileRenderer;
//}
//
//
//
//
//
//namespace DM
//{
//    class Texture;
//}
//
//
//
//
//
//class SDV::TileRenderer :
//    public DM::RenderComponent
//{
//
//public:
//
//    TileRenderer(const DM::GameObject* owner, const std::wstring& name = L"");
//    virtual ~TileRenderer() override;
//
//    virtual void Initialize() override;
//    virtual void Update() override;
//    virtual void Render(HDC hdc) const override;
//
//
//public:
//
//    void SetTexture(DM::Texture* texture) { this->texture = texture; }
//
//    DM::Texture* GetTexture() const { return this->texture; }
//
//
//private:
//
//    void render_bmp(HDC hdc) const;
//    void render_png(HDC hdc) const;
//
//    void renderTile_bmp(HDC hdc) const;
//    void renderTile_png(HDC hdc) const;
//
//
//private:
//
//    DM::Texture* texture;
//
//
//};
//
