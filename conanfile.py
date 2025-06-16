from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps


class resumoRecipe(ConanFile):
    name = "resumo"
    version = "0.1"
    package_type = "application"

    # Optional metadata
    license = ""
    author = "Marcus Chaves"
    url = ""
    description = "Gera o resumo criptografico em SHA-512 do arquivo especificado em outro arquivo especificado"
    topics = ("", "", "")

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"

    # Sources are located in the same place as this recipe, copy them to the recipe
    exports_sources = "CMakeLists.txt", "src/*"

    def requirements(self):
        self.requires("poco/1.11.0")

    def layout(self):
        cmake_layout(self)

    def configure(self):
        self.options["poco"].enable_data_postgresql = False
        self.options["poco"].enable_data_mysql = False
        self.options["poco"].enable_activerecord = False
        self.options["poco"].enable_activerecord_compiler = False
        self.options["poco"].enable_apacheconnector = False
        self.options["poco"].enable_cppparser = False
        self.options["poco"].enable_data = False
        self.options["poco"].enable_data_odbc = False
        self.options["poco"].enable_data_sqlite = False
        self.options["poco"].enable_encodings = False
        self.options["poco"].enable_fork = False
        self.options["poco"].enable_json = False
        self.options["poco"].enable_jwt = False
        self.options["poco"].enable_mongodb = False
        self.options["poco"].enable_pagecompiler = False
        self.options["poco"].enable_pagecompiler_file2page = False
        self.options["poco"].enable_pdf = False
        self.options["poco"].enable_pocodoc = False
        self.options["poco"].enable_redis = False
        self.options["poco"].enable_sevenzip = False
        self.options["poco"].enable_xml = False
        self.options["poco"].enable_zip = False

    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()

    

    
