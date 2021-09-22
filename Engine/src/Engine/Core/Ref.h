#pragma once
#include <atomic>

namespace Engine {
	class RefCounted {
	public:
		void IncRefCount() const {
			refCount++;
		}
		void DecRefCount() const {
			refCount--;
		}
		uint32_t GetRefCount() const {
			return refCount.load();
		}
	private:
		mutable std::atomic<uint32_t> refCount = 0;
	};

	template<typename T>
	class Ref {
	public:
		Ref() {}
		Ref(std::nullptr_t n) {}
		Ref(T* ins) : instance(ins) {
			static_assert(std::is_base_of(RefCounted, T)::value, "Class is not RefCounted!");
			IncRef();
		}
		//ͬ������ֵ�������캯��
		Ref(const Ref<T>& other): instance(other.instance) {
			IncRef();
		}
		//ͬ������ֵ�������캯��
		Ref(const Ref<T>&& other): instance(other.instance) {}
		//��ͬ������ֵ�������캯��
		template<typename T2>
		Ref(const Ref<T2>& other) : instance(other.instance) {
			IncRef();
		}
		//��ͬ������ֵ�������캯��
		template<typename T2>
		Ref(const Ref<T2>&& other) : instance(other.instance) {}
		//���պ���
		Ref& operator=(std::nullptr_t n) {
			DecRef();
			instance = nullptr;
		}
		//ͬ������ֵ��ֵ����
		Ref& operator=(const Ref<T>& other) {
			DecRef();
			instance = other.instance;
			IncRef();
			return *this;
		}
		//��ͬ������ֵ��ֵ����
		template<typename T2>
		Ref& operator=(const Ref<T2>& other) {
			DecRef();
			instance = other.instance;
			IncRef();
			return *this;
		}
		//ͬ������ֵ��ֵ����
		Ref& operator=(const Ref<T>&& other) {
			DecRef();
			instance = other.instance;
			other.instance = nullptr;
			return *this;
		}
		//��ͬ������ֵ��ֵ����
		template<typename T2>
		Ref& operator=(const Ref<T2>&& other) {
			DecRef();
			instance = other.instance;
			other.instance = nullptr;
			return *this;
		}
		//���ú���
		void Reset() {
			DecRef();
			instance = nullptr;
		}
		//==����
		bool operator==(const Ref<T>& other) {
			return instance == other.instance;
		}
		//!=����
		bool operator!=(const Ref<T>& other) {
			return instance != other.instance;
		}
		T* operator->() {
			return instance;
		}
		const T* operator->() {
			return instance;
		}
		T& operator*() {
			return *instance;
		}
		const T& operator*() {
			return *instance;
		}
		~Ref() {
			DecRef();
			instance = nullptr;
		}
	private:
		void IncRef() {
			if (instance) {
				instance->IncRefCount();
			}
		}
		void DecRef() {
			if (instance) {
				instance->DecRefCount();
				if (instance->GetRefCount() == 0) {
					delete instance;
					instance = nullptr;
				}
			}
		}
	private:
		template<class T2>
		friend class Ref;
		mutable T* instance = nullptr;
	};
}