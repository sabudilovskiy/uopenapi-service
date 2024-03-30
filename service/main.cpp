#include <userver/components/minimal_server_component_list.hpp>
#include <userver/clients/dns/component.hpp>
#include <userver/clients/http/component.hpp>
#include <userver/server/handlers/ping.hpp>
#include <userver/server/handlers/tests_control.hpp>
#include <userver/testsuite/testsuite_support.hpp>
#include <userver/utils/daemon_run.hpp>
#include <views/login/handler_fwd.hpp>
#include <views/register/handler_fwd.hpp>
#include <uopenapi/http/openapi_descriptor.h>
#include <userver/storages/postgres/component.hpp>

int main(int argc, char* argv[]) {
    auto component_list = userver::components::MinimalServerComponentList()
            .Append<userver::server::handlers::Ping>()
            .Append<userver::components::TestsuiteSupport>()
            .Append<userver::components::HttpClient>()
            .Append<userver::clients::dns::Component>()
            .Append<userver::server::handlers::TestsControl>();
    component_list.Append<uopenapi::http::openapi_descriptor>();
    component_list.Append<userver::components::Postgres>("todo_db");
    views::login::Append(component_list);
    views::Register::Append(component_list);

    return userver::utils::DaemonMain(argc, argv, component_list);
}