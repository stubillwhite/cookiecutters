# Constants
# ==============================================================================

COLOR_BLUE=\033[0;34m
COLOR_NONE=\033[0m

PYTHON_VERION=python3.13

PROJECT_NAME={{cookiecutter.package_name}}

SENTINEL_FILE_DEPS=.make-sentinel.deps

SHELL=zsh

export POETRY_VIRTUALENVS_IN_PROJECT=true

# Proxy certificates
export SSL_CERT_FILE=$(HOME)/dev/certificates/ZscalerRootCertificate-2048-SHA256.crt

TEST_FILE=tests/{{cookiecutter.package_name}}/test_console.py
# Targets
# ==============================================================================

# Help
# ======================================

help:
	@grep -E '^[0-9a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) \
		| sort \
		| awk 'BEGIN {FS = ":.*?## "}; {printf "$(COLOR_BLUE)%s|$(COLOR_NONE)%s\n", $$1, $$2}' \
		| column -t -s '|'

# Clean
# ======================================

.PHONY: stop
stop: ## Stop any running processes
	@echo 'Stopping processes'
	@poetry run dmypy stop || true

.PHONY: clean
clean: stop ## Remove all artefacts
	@echo 'Cleaning application'

.PHONY: clean-all
clean-all: clean ## Remove all artefacts and dependencies
	@echo 'Cleaning dependencies'
	@rm -rf dist/ htmlcov/
	@rm -f $(SENTINEL_FILE_DEPS)
	@poetry env remove --all
	@poetry env list --full-path | cut -f 1 -d ' ' | xargs rm -r

# Dependencies
# ======================================

$(SENTINEL_FILE_DEPS): pyproject.toml
	@echo 'Setting Python version to $(PYTHON_VERION)'
	@poetry env use $(PYTHON_VERION) 
	@echo 'Fetching dependencies'
	@poetry install
	@touch .make-sentinel.deps

deps: $(SENTINEL_FILE_DEPS) ## Install dependencies

.PHONY: deps-lock
deps-lock:
	@echo 'Locking poetry file'
	@poetry lock

.PHONY: deps-scan
deps-scan: deps
	@echo 'Scanning dependencies for security vulnerabilities'
	@poetry run pip-audit -r <(poetry export -f requirements.txt --with dev)

.PHONY: deps-update
deps-update: clean-all ## Update dependency versions
	@echo 'Updating dependencies'
	@poetry update

.PHONY: deps-add
deps-add: ## Add a dependency (use DEP=foo to specify the dependency)
	@poetry add $(DEP)

.PHONY: deps-remove
deps-remove: ## Remove a dependency (use DEP=foo to specify the dependency)
	@poetry remove $(DEP)

# Running
# ======================================

run: deps ## Run the app
	@echo 'Running application'
{% if cookiecutter.include_zscaler == 'yes' %}
	@export REQUESTS_CA_BUNDLE=$(SSL_CERT_FILE) \
		&& poetry run run-app
{% else %}
	@poetry run run-app
{% endif %}
	@echo

run-test-with-coverage: deps
	@echo 'Running test $(TEST_FILE)'
	@poetry run coverage run --source=src -m pytest $(TEST_FILE) 
	@poetry run coverage html

test: deps ## Run the tests
	@echo 'Running tests'
	@poetry run pytest --cov
	@poetry run coverage html
	@echo

check: deps ## Check the code
	@echo 'Running linter'
	@poetry run ruff check
	@echo
	@echo 'Running static type checks'
	@poetry run dmypy run -- src tests
	@echo

fix: format deps ## Fix formatting and minor style issues
	@echo 'Fixing problems'
	@poetry run ruff check --fix
	@echo

format: deps ## Format the code
	@echo 'Formatting code'
	@poetry run isort src tests
	@poetry run black src tests
	@echo

build: format test check ## Build the code
	@echo 'Building artefacts'
	@poetry build
