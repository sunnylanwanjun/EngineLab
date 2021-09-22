#pragma once

namespace Engine {

	enum class RendererAPIType {
		None,
		OpenGL
	};

	class RendererAPI {
	public:
		virtual void Init() = 0;
		virtual void Shutdown() = 0;

		virtual void BeginFrame() = 0;
		virtual void EndFrame() = 0;

		virtual void BeginRenderPass() = 0;

		static RendererAPIType Current() {
			return CurrentRendererAPI;
		}
		static void SetAPI(RendererAPIType api);
	private:
		inline static RendererAPIType CurrentRendererAPI = RendererAPIType::OpenGL;
	};
}