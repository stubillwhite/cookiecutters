{% raw -%}
# vim:fdm=marker

# Constants                                                                 {{{1
# ==============================================================================

COLOR_BLUE=\033[0;34m
COLOR_NONE=\033[0m

{% endraw %}
EXECUTABLE=./build/apps/{{cookiecutter.project_name}}-app
{% raw -%}


# Targets                                                                   {{{1
# ==============================================================================

# Help                              {{{2
# ======================================

help:
	@grep -E '^[0-9a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) \
		| sort \
		| awk 'BEGIN {FS = ":.*?## "}; {printf "$(COLOR_BLUE)%s|$(COLOR_NONE)%s\n", $$1, $$2}' \
		| column -t -s '|'

# Clean                             {{{2
# ======================================

.PHONY: clean
clean: ## Remove all artefacts
	@echo 'Cleaning application'
	@rm -rf \
		./build \
		./docs/html \
		./docs/latex \
		./docs/xml

.PHONY: clean-all
clean-all: clean ## Remove all artefacts and dependencies
	@echo 'Cleaning dependencies'

# Build                             {{{2
# ======================================

.PHONY: build
build: 
	@echo 'Building application'
	@mkdir -p build 
	@cd build \
		&& cmake -DCMAKE_PROJECT_TOP_LEVEL_INCLUDES=cmake/conan_provider.cmake .. \
		&& cmake --build .

.PHONY: run
run: build ## Build and run
	@echo 'Running application'
	@$(EXECUTABLE)

.PHONY: test
test: build
	@cd build \
		&& ctest

# Documentation                     {{{2
# ======================================

.PHONY: docs
docs: build ## Generate documentation with Doxygen
	@echo 'Generating documentation'
	@cd build \
		&& cmake --build . --target docs		
{% endraw %}
